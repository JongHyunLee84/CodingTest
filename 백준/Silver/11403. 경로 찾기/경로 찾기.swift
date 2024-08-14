import Foundation

let n = Int(readLine()!)!
var arr = [[Int]]()
for _ in 0..<n {
    let temp = readLine()!.split(separator: " ").map { Int($0)! }
    arr.append(temp)
}

let result = findPath(n, arr)
for i in 0..<result.count {
    for j in 0..<result.count {
        print(result[i][j], terminator: " ")
    }
    print("")
}

public func findPath(_ n: Int, _ arr: [[Int]]) -> [[Int]] {
    var connected = Array(repeating: [Int](), count: n)
    var result = Array(repeating: Array(repeating: 0, count: n), count: n)
    
    for i in 0..<n {
        for j in 0..<n {
            if arr[i][j] == 1 {
                connected[i].append(j)
                result[i][j] = 1
            }
        }
    }
    
    for i in 0..<n {
        for j in 0..<n {
            if isConnected(i, j) {
                result[i][j] = 1
            }
        }
    }
    
    func isConnected(_ y: Int, _ x: Int) -> Bool {
        var queue = connected[y]
        var visited = Array(repeating: 0, count: n)
        while !queue.isEmpty {
            let temp = queue.removeFirst()
            if visited[temp] == 1 { continue }
            visited[temp] = 1
            if connected[temp].contains(x) {
                return true
            }
            queue.append(contentsOf: connected[temp])
        }
        return false
    }
    return result
}