func solution(_ arr:[Int]) -> [Int] {
    var result = arr
    var min = Int.max
    for i in arr {
        if i < min {
            min = i
        }
    }
    result.remove(at: result.firstIndex(of: min)!)
    return arr.count == 1 ? [-1] : result 
}