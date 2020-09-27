struct edge_info {
    int dst;
    int value;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //new edge list
        vector<vector<edge_info>> sparse_matrix;
        vector<int> dst;
        vector<int> result;
        vector<int> relax;
        // relax queue
        dst.resize(N+1, INT_MAX);
        dst[K] = 0;
        result.resize(N+1, INT_MAX);
        result[K] = 0;
        relax.resize(N+1, INT_MAX);
        
        sparse_matrix.resize(N+1);
        for(auto edge : times) {
            struct edge_info new_edge;
            new_edge.dst   = edge[1];
            new_edge.value = edge[2];
            sparse_matrix[edge[0]].push_back(new_edge);
        }
        int i;
        int min_value;
        for(i = 1 ; i <= N; i++) {
            // find min dst
            min_value = INT_MAX;
            int min_index = -1;
            for(int j = 1 ; j <= N ; j++) {
                if(dst[j] < min_value && relax[j] != 1) {
                    min_index = j;  
                    min_value = dst[j];
                }
            }
            if(min_value == INT_MAX) return -1;
            result[min_index] = min_value;
            for(auto edge_fo : sparse_matrix[min_index]) {
                if(dst[edge_fo.dst] > edge_fo.value + min_value) {
                    dst[edge_fo.dst] =  edge_fo.value + min_value;
                }
            }
            relax[min_index] = 1;
        }
        return min_value;
    }
};