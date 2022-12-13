func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    var result : [Int] = []
    for i in arr.sorted() {
        if i % divisor == 0 {
            result.append(i)
        }
    }
    return result.isEmpty ? [-1] : result 
}