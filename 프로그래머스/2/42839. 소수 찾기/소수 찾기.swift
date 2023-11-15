import Foundation

func solution(_ numbers:String) -> Int {
    var maxNum = makeMax(numbers)
    var ret = 0
    if maxNum < 2 { return 0 }
    var tempPrimeArray = Array(repeating: true, count: maxNum+1)
    var primeArray: [Int] = []
    for i in 2...maxNum {
        if tempPrimeArray[i] {
            var j = 2
            while(i * j <= maxNum) {
                tempPrimeArray[i*j] = false
                j += 1
            }
        }
    }
    for i in 2..<tempPrimeArray.count {
        if tempPrimeArray[i] == true {
            primeArray.append(i)
        }
    }
    for i in primeArray {
        var temp = numbers
        var shouldPlus = true
        for j in String(i) {
            if let index = temp.firstIndex(of: j) {
                temp.remove(at: index)
            } else { 
            shouldPlus = false
            break
            }
        }
        if shouldPlus { ret += 1 }
    }
    return ret
}

func makeMax(_ num: String) -> Int {
    let array: [Int] = num.map { Int(String($0))! }
    let maxNum = array.sorted(by: >)
    return Int(maxNum.map { String($0) }.joined())!
}