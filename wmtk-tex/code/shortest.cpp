//Save two vertices attached to edge t
bool collapse_before(const Tuple& t)
{
    cache.v1p = verts[t.vid()];
    cache.v2p = verts[switch_vertex(t).vid()];
    return true;
}

//Generate a new point 
bool collapse_after(const Tuple& t)
{
    verts[t.vid()] = (cache.v1p + cache.v2p) / 2.0;
    return true;
}