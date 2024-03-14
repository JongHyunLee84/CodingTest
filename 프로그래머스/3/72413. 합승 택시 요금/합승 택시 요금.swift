import Foundation
// 다익스트라, 벨만포트 이용하기

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var result = Int.max
    var nested = Array(repeating: Array(repeating: 100000 * n, count: n+1), count: n+1)
    for i in fares {
        var first = i[0]
        var second = i[1]
        var value = i[2]
        nested[first][second] = value
        nested[second][first] = value
    }
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                nested[i][j] = min(nested[i][j], nested[i][k] + nested[k][j])
            }
        }
    }
    
    for i in 1...n {
        nested[i][i] = 0
    }
    
    for i in 1...n {
        result = min(result, nested[i][s] + nested[i][a] + nested[i][b])
    }
    return result
}