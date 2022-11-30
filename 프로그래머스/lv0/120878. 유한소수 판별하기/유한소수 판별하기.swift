import Foundation

func solution(_ a:Int, _ b:Int) -> Int {
    var array = [a, b]
    var div : [Int] = []
    var n = 2
    while n <= a {
        if array[0] % n == 0 && array[1] % n == 0 {
            array[0] /= n 
            array[1] /= n
        } else {
            n += 1
        }
    }
    n = 2
    var num = array[1]
    if num == 1 {
        return 1
    }
    while n <= array[1] {
        if num % n == 0 {
            num /= n
            div.append(n)
        } else {
            n += 1
        }
    }
    var result = Set(div)
switch result.sorted() {
    case [2] :
    return 1
    case [5] :
    return 1
    case [2,5] :
    return 1
    default :
    return 2
}
}