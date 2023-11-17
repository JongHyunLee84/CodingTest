import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var array = Array(repeating: [Int](), count: n+1)
    var visited = Array(repeating: false, count: n+1)
    var ret = Int.max
    for i in wires {
        array[i[0]].append(i[1])
        array[i[1]].append(i[0])
    }
    print(array)
    func bfs(_ idx: Int) {
        for i in array[idx] {
            if !visited[i] {
                visited[i] = true
                bfs(i)
            }
        }
    }
    for i in 1..<array.count {
        if array[i].count >= 1 {
            for j in array[i] {
            visited = Array(repeating: false, count: n+1)
            array[i].remove(at: array[i].firstIndex(of: j)!)
            array[j].remove(at: array[j].firstIndex(of: i)!)
            bfs(i)
            
            let iCount = visited.filter { $0 == true}.count
            // print(i, iCount)
                
            visited = Array(repeating: false, count: n+1)
            bfs(j)
            let jCount = visited.filter { $0 == true}.count
            ret = min(ret, abs(max(1,iCount) - max(1,jCount)))
            
            // print(j, jCount)
            // print(abs(max(1,iCount) - max(1,jCount)))
            // print("--------")
            array[i].append(j)
            array[j].append(i)
            }
        }
    }

    
    return ret
}

