import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var array = [Int](0..<dungeons.count)
    var permutations = permutation(array, array.count)
    var ret = 0
    for i in permutations {
        var temp = k
        var tempRet = 0
        for j in i {
            if dungeons[j][0] <= temp {
                temp -= dungeons[j][1]
                tempRet += 1
            }
        }
        ret = max(ret, tempRet)
    }
    return ret
}

func permutation(_ array: [Int], _ n: Int) -> [[Int]] {
    var result = [[Int]]()
    if array.count < n { return result }
    
    var visited = Array(repeating: false, count: array.count)
    
    func go(_ now: [Int]) {
        if now.count == n {
            result.append(now)
            return 
        }
        
        for i in 0..<array.count {
            if visited[i] {
                continue
            } else {
                visited[i] = true
                go(now + [array[i]])
                visited[i] = false
            }
        }
    }
    
    go([])
    
    return result
}