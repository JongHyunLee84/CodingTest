import Foundation

func solution(_ n:Int, _ weak:[Int], _ dist:[Int]) -> Int {
    // 직선으로 펼쳐서 
    var arr = [[Int]]()
    
    for i in 1...dist.count {
        arr.append(contentsOf: permutation(dist, i))
    }
    var weaks = makeWeaks(weak, n)
    for i in arr {
        if check(i, weaks) { return i.count }
    }
    return -1
}

func check(_ arr: [Int], _ weak: [[Int]]) -> Bool {
    for i in weak {
        var sum = i[0]
        var idx = 0
        let count = i.count
        for j in arr {
            sum += j
            while true {
                if idx >= count { break }
                if i[idx] <= sum { idx += 1 }
                else { sum = i[idx]; break }
            }
        }
        if idx >= count { return true }
    }
    return false
}

func makeWeaks(_ arr: [Int], _ n: Int) -> [[Int]] {
    var result = [[Int]]()
    for i in 0..<arr.count {
        var temp = [Int]()
        for j in i..<i+arr.count {
            let idx = j % arr.count
            if temp.isEmpty { temp.append(arr[idx]) }
            else if temp.first! > arr[idx] { temp.append(arr[idx]+n) }
            else { temp.append(arr[idx]) }
        }
        result.append(temp)
    }
    return result
}

func permutation<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return result }

    var visited = Array(repeating: false, count: array.count)
    
    func cycle(_ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in 0..<array.count {
            if visited[i] {
                continue
            } else {
                visited[i] = true
                cycle(now + [array[i]])
                visited[i] = false
            }
        }
    }
    
    cycle([])
    
    return result
}