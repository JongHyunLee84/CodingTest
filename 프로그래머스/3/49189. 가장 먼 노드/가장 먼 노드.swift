import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var visited = Array(repeating: 0, count: n+1)
    var array: [[Int]] = Array(repeating: [], count: n+1)
    
    for i in edge {
        array[i[0]].append(i[1])
        array[i[1]].append(i[0])
    }
    
    func bfs() -> Int {
        var queue: [Int] = [1]
        visited[1] = 1
        while(queue.count != 0) {
            let first = queue.removeFirst()
            
            for i in array[first] {
                if visited[i] == 0 {
                    visited[i] = visited[first] + 1
                    queue.append(i)
                    // print(i, visited[i])
                }
            }
        }
        
        let maxNum = visited.max()!
        return visited.filter { $0 == maxNum }.count
    }
    var ret = bfs()
    return ret
}