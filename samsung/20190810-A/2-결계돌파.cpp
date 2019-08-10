/*
@param  __map 변경할 맵. 미리 memcpy해놓은 copy_map
@param  __r   왜곡이 일어날 중심의 행수
@param  __c   왜곡이 일어날 중심의 열수
@param  __l   왜곡의 범위
*/
void tweaks(int __map[][15], const int &__r, const int &__c, const int &__l) {
    // 방향은 아래, 오른쪽, 위, 왼쪽으로 반시계로 가면서 당겨줌 == 시계로 밀림.
    const int dr[] = {1, 0, -1, 0};
    const int dc[] = {0, 1, 0, -1};
    // nd[0]  거리 0짜리 시계회전은 없음.
    // nd[1]  거리 1짜리 시계회전시 8개중에 7번은 포문으로 밀고 마지막은 수동으로.
    // nd[2]  거리 2짜리 시계회전시 16개중에 15번은...
    // nd[3]  거리 3짜리 시계회전시 24개...
    const int nd[4][4] = {{}, {2, 2, 2, 1}, {4, 4, 4, 3}, {6, 6, 6, 5}};
    for (int l = __l; 0 < l; --l) {
        int cr = __r - l;
        int cc = __c - l;
        // 최초의 하나는 tmp로 옮겨야함
        int tmp = __map[cr][cc];
        int nr, nc;
        // 네 방향 반복.
        for (int d = 0; d < 4; ++d) {
            // 각 방향마다 반복 횟수는 nd만큼.
            for (int n = nd[l][d]; 0 < n; --n) {
                nr = cr + dr[d];
                nc = cc + dc[d];
                __map[cr][cc] = __map[nc][nc];
                cr = nr;
                cc = nc;
            }
        }
        __map[nr][nc] = tmp;
    }
}
