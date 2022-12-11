func solution(_ arr:[Int]) -> Double {
    var a = 0
    for i in arr {
        a += i
    }
    return Double(a) / Double(arr.count)
}