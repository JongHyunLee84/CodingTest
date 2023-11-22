func solution(_ arr:[Int]) -> Int {
    var maxNum = arr.max()!
    var multiple = 1
    while true {
        let temp = maxNum * multiple
        multiple += 1
        var allTrue = true
        for i in arr {
            if temp % i != 0 {
                allTrue = false
                break
            }
        }
        if allTrue {
            return temp
        }
    }
    return 0
}