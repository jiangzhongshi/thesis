template <class Mesh>
struct Scheduler
{
    function<double
        (const Mesh&, Op op, const Tuple&)> 
        priority = ...;
    
    function<vector<pair<Op, Tuple>>
        (const Mesh&, Op, const vector<Tuple>&)>
        renew_neighbor_tuples = ...;
        
    function<vector<size_t>
        (Mesh&, const Tuple&)>
        lock_vertices = ...

    function<bool(const Mesh&)> 
        stopping_criterion = ...;

    function<bool
        (const Mesh&, tuple<double, Op, Tuple>& t)>
        should_process = ...;

    size_t num_threads = ...;
    size_t max_retry_limit = ...;
    size_t stopping_criterion_checking_frequency = ...;
    
    bool operator()
        (Mesh& m, 
        const vector<pair<Op, Tuple>>& ops);
};