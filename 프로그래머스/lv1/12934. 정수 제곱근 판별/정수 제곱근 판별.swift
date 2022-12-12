func solution(_ n:Int64) -> Int64 {
    var result : Int64 = 0
    // var num : Int64 = 1
    for i in 1...n {
        if i * i == n {
            result = i
            break
        }

    }
    return result == 0 ? -1 : (result+1) * (result+1)
}