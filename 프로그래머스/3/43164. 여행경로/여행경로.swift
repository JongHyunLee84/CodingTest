import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var visited: [Bool] = Array(repeating: false, count: tickets.count)
    var array: [[String]] = []
    func dfs(_ city: String, _ route: [String]) {
        if !visited.contains(false) {
            array.append(route + [city])
            return
        }
        for i in 0..<tickets.count {
            if !visited[i] && tickets[i][0] == city {
                visited[i] = true
                dfs(tickets[i][1], route + [city])
                visited[i] = false
            }
        }
    }
    dfs("ICN", [])
    if array.count == 1 { return array[0] }
    while array.count > 1 {
        var isDeleted = false
        for i in 0..<array[0].count {
            if array[0][i] < array[1][i] {
                array.remove(at: 1)
                isDeleted = true
                break
            } else if array[0][i] > array[1][i] {
                array.removeFirst()
                isDeleted = true
                break
            }
        }
        if !isDeleted { array.removeFirst() }
    }
    
    return array[0]
    // 마지막에 가능한 경로들끼리 알파벳 기준으로 sort해야함
}