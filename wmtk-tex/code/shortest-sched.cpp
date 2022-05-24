//Collect edges attacched to tris
vector<Tuple> new_edges_after(const vector<Tuple>& tris)
{
    vector<Tuple> new_edges;
    for (auto t : tris) {
        for (auto j = 0; j < 3; j++) {
            new_edges.push_back(
                tuple_from_edge(t.fid(), j));
        }
    }
    return new_edges;
}

bool collapse_shortest(int n_collapses)
{
    //Register operations
    auto ops = vector<pair<Op, Tuple>>();
    for (auto& l : get_edges())
        ops.emplace_back("edge_collapse", l);

    //After a successful operation,
    //we append all new edges
    auto renew = [](auto& m, auto op, auto& tris) {
        auto edges = m.new_edges_after(tris);
        auto optup = vector<pair<Op, Tuple>>();
        for (auto& e : edges)
            optup.emplace_back("edge_collapse", e);
        return optup;
    };

    //priority in which we collapse
    auto priority = [](auto& m, auto op, const Tuple& e) {
        const auto v1 = m.verts[e.vid()];
        const auto v2 = m.verts[e.switch_vertex(m).vid()];
        auto len2 = (v1 - v2).squaredNorm();
        return -len2;
    };

    //Set the functions to the scheduler
    Scheduler executor;
    executor.renew_neighbor_tuples = renew;
    executor.priority = priority;
    executor.stopping_criterion_checking_frequency =
                n_collapses;
    //We stop only when we perform n_collapses
    executor.stopping_criterion =
                [](auto& m) { return true; };
    //Run the executor
    executor(*this, ops);
}