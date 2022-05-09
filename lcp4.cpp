class Solution {
    int n;
    vector<vector<string>> ss;
    bool A[10][10][10];
    int v[6];

// 每个面的起始位置
    int CUBE_BASE[6][3] = {
        0, 0, 0,
        0, 0, 1,
        1, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 1, 1
    };
    // 每个面 xyz 的增加“方向”
    int CUBE_DIR[6][6] = {
        1, 0, 0, 0, 1, 0,
        1, 0, 0, 0, 1, 0,
        0, 0, -1, 0, 1, 0,
        0, 0, -1, 0, 1, 0,
        0, 0, -1, 1, 0, 0,
        0, 0, -1, 1, 0, 0
    };

    //形状旋转后到起始位置
    int SHAPE_BASE[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    // 形状旋转后行和列的增加“方向”
    int SHAPE_DIR[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};

    // x:哪个形状
    // k:哪个面
    // s:哪种旋转
    // rc:行列是否交换
    // modify: 0:检查是否占用 1:占用 -1:取消占用
    bool gao(int x,int k,int s,bool rc,int modify){
        for(int i = 0; i < n;i++) for(int j = 0; j < n;j++){
            int x = CUBE_BASE[k][0] * (n - 1) + CUBE_BASE[k][0] * i + CUBE_BASE[k][3] * j;
            int y = CUBE_BASE[k][1] * (n - 1) + CUBE_BASE[k][1] * i + CUBE_BASE[k][4] * j;
            int z = CUBE_BASE[k][2] * (n - 1) + CUBE_BASE[k][2] * i + CUBE_BASE[k][5] * j;
            int sx = SHAPE_BASE[s][0] * (n - 1) + SHAPE_DIR[s][0] * (rc ? j : i);
            int sy = SHAPE_BASE[s][1] * (n - 1) + SHAPE_DIR[s][1] * (rc ? i : j);
            if(ss[x][sx][sy] == '1'){
                if(modify == 1) A[x][y][z] = true;
                else if(modify == -1) A[x][y][z] = false;
                else if(A[x][y][z]) return false;
            }
        }
        return true;
    }
    bool dfs(int x){
        if(x == 6) return true;
        for(int i = 0; i < 6; i++) if(!v[i]){
            for(int j = 0; j < 4; j++) for(int k = 0;k <= 1;k++){
                if(!gao(x,i,j,k,0)) continue;
                gao(x,i,j,k,1);
                v[i] = true;
                if(dfs(x + 1)) return true;
                v[i] = false;
                gao(x,i,j,k,-1);
            }
        }
    }
public:
    bool composeCube(vector<vector<string>>& shapes) {
        n = ss[0].length;
        int exp = n * n * n - (n - 2) * (n - 2) * (n - 2);
        int act = 0;
        for(auto &s:ss) for(auto &l:s) for(auto &c:l) act += c - '0';
        if(exp != act) return false;
        this->ss = ss;
        return dfs(0);
    }
};