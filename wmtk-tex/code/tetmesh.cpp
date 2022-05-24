class TetMesh
{
public:

    bool split_edge(const Tuple& t, 
        std::vector<Tuple>& new_tets);
    bool collapse_edge(const Tuple& t,
        std::vector<Tuple>& new_tets);
    bool swap_edge(const Tuple& t,
        std::vector<Tuple>& new_tets);
    bool swap_face(const Tuple& t,
        std::vector<Tuple>& new_tets);
    bool smooth_vertex(const Tuple& t);

    bool insert_triangle(
        const std::vector<Tuple>& intersected_tets,
        const std::vector<Tuple>& intersected_edges);

protected:

    bool invariants(const std::vector<Tuple>& tets);
    
    bool split_before(const Tuple& t);
    bool split_after(const Tuple& t);

    bool collapse_before(const Tuple& t);
    bool collapse_after(const Tuple& t);
    
    bool swap_edge_before(const Tuple& t);
    bool swap_edge_after(const Tuple& t);
    
    bool swap_face_before(const Tuple& t);
    bool swap_face_after(const Tuple& t);
    
    bool smooth_before(const Tuple& t);
    bool smooth_after(const Tuple& t);
    
    bool insert_triangle_before(
        const std::vector<Tuple>& faces);
    bool insert_triangle_after(
        const std::vector<Tuple>& faces,
        const std::vector<std::vector<Tuple>>& new_f);
};
