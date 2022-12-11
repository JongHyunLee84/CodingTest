func solution(_ n:Int) -> Int {
    var array : [Int] = []
    if n == 0 {
        return 0
    }
    for i in 1...n {
        if n % i == 0 {
            array.append(i)
        }
    }
    return array.reduce(0, +)
}