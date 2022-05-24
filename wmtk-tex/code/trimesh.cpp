
class TriMesh
{
public:

    bool split_edge(const Tuple& t,
        std::vector<Tuple>& new_t);
    bool collapse_edge(const Tuple& t,
        std::vector<Tuple>& new_t);
    bool swap_edge(const Tuple& t,
        std::vector<Tuple>& new_t);
    bool smooth_vertex(const Tuple& t);

protected:

    bool invariants(const std::vector<Tuple>& tris);
    
    bool split_before(const Tuple& t);
    bool split_after(const Tuple& t);
    
    bool collapse_before(const Tuple& t);
    bool collapse_after(const Tuple& t);

    bool swap_after(const Tuple& t);
    bool swap_before(const Tuple& t);
};