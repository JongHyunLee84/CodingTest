func solution(_ x:Int, _ n:Int) -> [Int64] {
    var array : [Int64] = []
    var num : Int64 = 0
    for _ in 0..<n {
        num += Int64(x)
        array.append(num)
    }
    return array
}