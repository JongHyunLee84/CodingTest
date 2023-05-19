 #include <bits/stdc++.h>
 using namespace std;
 
int n, m, ss, ar[104][104], br[104][104], ret;
vector<vector<int>> sharks;
int ta, tb, tc, td, te, dy[4] = {-1,1,0,0}, dx[4] = {0,0,1,-1};

void print_(){
            for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
}

void print_s() {
        for(int i=0; i<ss; i++){
        cout << sharks[i][0] << sharks[i][1] << sharks[i][2];
        cout << '\n';
    }
}

void move_(int y, int x, int s, int d, int size_, int idx){
	        int ny, nx; 
			while (1) {  
				ny = y + s * dy[d];
				nx = x + s * dx[d]; 
                if (nx < m && ny < n && ny >= 0 && nx >= 0)break;
				if(d <= 1){
					if(ny < 0){
						s -= y;
						y = 0;
					}else{
						s -= n - 1 - y;
						y = n - 1;
					} 
				}else{ 
					if(nx < 0){
						s -= x;
						x = 0;
					}else {
						s -= m - 1 - x;
						x = m - 1;
					} 
				}
				d ^= 1;  
            }
    if(br[ny][nx] > size_){
        sharks[idx][4] = 0;
        return;
    } else if(br[ny][nx] && br[ny][nx] < size_) {
        for(int i=0; i<ss; i++){
            if(sharks[i][0] == ny && sharks[i][1] == nx && sharks[i][4]) {
                sharks[i][4] = 0;
                break;
            }
        }
    }
    br[ny][nx] = size_;
    sharks[idx][0] = ny;
    sharks[idx][1] = nx;
    sharks[idx][3] = d;
}

void move() {
    memset(br, 0, sizeof(br));
                for(int k=0; k<ss; k++){
                    if(sharks[k][4] == 0)continue;
                    if(ar[sharks[k][0]][sharks[k][1]] == 0){
                        sharks[k][4] = 0;
                        continue;
                    }
                    move_(sharks[k][0],sharks[k][1],sharks[k][2], sharks[k][3], sharks[k][4], k);
                } 
    memcpy(ar, br, sizeof(br));
    // print_();
    // cout << sharks[7][0] << '.' << sharks[7][1] << '\n';
    // cout << '\n';
}

 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> ss;
    for(int i=0; i<ss; i++){
        cin >> ta >> tb >> tc >> td >> te;
        ar[--ta][--tb] = te;
        td--;
        if(td <= 1) tc %= (2 * (n - 1));
		else tc %= (2 * (m - 1));
        sharks.push_back({ta, tb, tc, td, te});
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){ // 열마다 한번씩 상어 잡기
            if(ar[j][i]){
                ret += ar[j][i];
                ar[j][i] = 0;
                break;
            }
        }
        // 이동
        move();
    }
    cout << ret << '\n';
    return 0;
 }