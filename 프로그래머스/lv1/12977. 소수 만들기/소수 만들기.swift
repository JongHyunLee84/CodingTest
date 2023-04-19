import Foundation

func solution(_ nums:[Int]) -> Int {
    var arrays = combination(nums, 3)
    return arrays.filter {
        
        for i in 2..<$0.reduce(0,+) {
            if $0.reduce(0,+) % i == 0 {
                return false
            }
        }
        return true
    }.count
}

    func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return result }

    func cycle(_ index: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    
    cycle(0, [])
    
    return result
}