import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    //모든 컴퓨터에 대해서 dfs를 하는데 visited 상태관리
    var visited = Array(repeating: false, count: n)
    var array: [[Int]] = Array(repeating: [], count: n)
    var ret = 0
    for i in 0..<computers.count {
        for j in 0..<computers[i].count {
            if i == j { continue }
            if computers[i][j] == 1 {
               array[i].append(j) 
            }
            
        }
    }
    // print(array)
    func dfs(_ idx: Int) {
        for i in array[idx] {
            if !visited[i] {
                visited[i] = true
                dfs(i)
            } 
        }
    }
    for i in 0..<n {
        if !visited[i] {
            dfs(i)
            ret += 1
        }
    }
    return ret
}