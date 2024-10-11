import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    // 결과가 하나라도 있다면 그 결과보다 사전순으로 빠르지 않은 애들은 없앰.
    // k를 넘어가는 애들은 없앰
    // 출발지점부터 탈출지점까지 dfs, 이미 왔던 곳 한번 더 갈수있음. 
    // 충족하는 결과가 없다면 impossible 리턴
    var result: String? 
    var array: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
    var visited: [[Dictionary<Int, String?>]] = Array(repeating: Array(repeating: .init(), count: m), count: n)
    for i in 0..<n {
        for j in 0..<m {
            let a = abs(i-(r-1))
            let b = abs(j-(c-1))
            array[i][j] = a+b
        }
    }
    var dx = [0, -1, 1, 0]
    var dy = [1, 0, 0, -1]
    var dir = ["d", "l", "r", "u"]
    func dfs(_ ty: Int, _ tx: Int, _ tk: Int, _ temp: String) {
        // 이미 k번째에 특정 위치에 도달했던 적이 있으면 최소 사전 빼고는 다 제외 
        if let visit = visited[ty][tx][tk] {
            if isOver(visit, temp) {  
                return 
            }
        }
        visited[ty][tx][tk] = temp
        // 최단 거리 내로 종료위치까지 못가는 애들 종료
        if tk + array[ty][tx] > k { 
            return
        }
        // 남은 거리는 홀/짝인데 소모해야하는 k는 짝/홀인 경우 종료
        let remainedDistance = abs(ty-(r-1)) + abs(tx-(c-1))
        let shouldUseK = k - tk
        if remainedDistance % 2 == 0 && shouldUseK % 2 == 1 {
            return 
        } else if remainedDistance % 2 == 1 && shouldUseK % 2 == 0 {
            return
        }
        // k를 넘어갔으면 종료
        if tk > k { return }
        // result에 값이 있고 현재 temp가 사전순으로 더 뒤에 있다면 종료 
        if let result = result, isOver(result, temp) { return }
        // k번째에 도착지점에 딱 도착하고, 사전순으로 더 빠르다면 result에 할당하고 return
        if tk == k && ty == r-1 && tx == c-1 && !isOver(result, temp) { 
            result = temp
            return
        }
        // 상하좌우로 움직이며 움직인 위치를 기반으로 temp에 더해주고, k를 올려주고 해당 위치의 y,x값을 할당해서 재귀
        for i in 0..<4 {
            let ny = ty + dy[i]
            let nx = tx + dx[i]
            if ny >= n || ny < 0 || nx >= m || nx < 0 { continue }
            dfs(ny, nx, tk+1, temp+dir[i])
        }
    }
    dfs(x-1, y-1, 0, "")
    return result == nil ? "impossible" : result!
}

func isOver(_ first: String?, _ second: String) -> Bool {
    guard let first = first else { return false }
    let fa = Array(first)
    let sa = Array(second)
    for i in 0..<second.count {
        if fa[i] < sa[i] {
            return true
        } else if fa[i] > sa[i] {
            return false
        }
    }
    return false
}