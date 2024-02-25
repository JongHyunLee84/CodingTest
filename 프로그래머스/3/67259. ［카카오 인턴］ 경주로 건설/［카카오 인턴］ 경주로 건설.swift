import Foundation

var n = 0
var result = Int.max
var visited: [[Int]] = []
var backTracking: [[Int]] = [] // 특정 위치에 더 큰 sum으로는 올 필요가 없다.
var dy = [-1, 1, 0, 0], dx = [0, 0, -1, 1] // 상: 0 하:1 좌:2 우:3
var board: [[Int]] = []
func solution(_ _board:[[Int]]) -> Int {
    n = _board.count
    visited = Array(repeating: Array(repeating: 0, count: n), count: n)
    backTracking = Array(repeating: Array(repeating: Int.max, count: n), count: n)
    board = _board
    go(0,0,0,0)
    // return 최소비용
    return result
} 

func go(_ y: Int, _ x: Int, _ sum: Int, _ di: Int) {
    // 0,0부터 ~ n-1,n-1
    if y == n - 1 && x == n - 1 {
        result = min(result, sum)
        return 
    }
    // 백트래킹
    if sum >= result { return } 
    if backTracking[y][x] == Int.max { backTracking[y][x] = sum }
    else if backTracking[y][x] + 500 < sum { return }
    else { backTracking[y][x] = min(backTracking[y][x],sum) }
    
    // visited로 움직이고 원복
    // 상하좌우, 벽 x, 양 모서리 그 이상 x, visited x
    for i in 0..<4 {
        let ny = dy[i] + y 
        let nx = dx[i] + x
        if ny < 0 || nx < 0 || ny >= n || nx >= n { continue }
        // 0은 갈 수 있고, 1은 못 가고
        if board[ny][nx] == 1 || visited[ny][nx] == 1 { continue }
        // 0,0 시작은 방향이 달라도 코너를 만드는 게 아님
        visited[y][x] = 1
        // 한칸 이동할 때마다 100원
        // 현재 이동 방향을 다음에 넘긴다.
        if x == 0 && y == 0 {
            go(ny, nx, sum + 100, i)
        } else if di == i {
            go(ny, nx, sum + 100, i)
        } else {
            // 상하좌우 방향이 바뀔 때마다 + 500원
            go(ny, nx, sum + 100 + 500, i)
        }
        visited[y][x] = 0
    }
    
}