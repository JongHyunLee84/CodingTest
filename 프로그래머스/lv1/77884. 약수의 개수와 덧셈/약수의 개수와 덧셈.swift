import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var array : [Int] = []
    for i in left...right {
        var a : [Int] = []
        var n = 1
        while n <= i {
            if i % n == 0 {
                a.append(n)
            }
        n += 1
        }
        if a.count % 2 == 0 {
            array.append(i)
        } else {
            array.append(i * -1)
        }
    }
    return array.reduce(0, +)
}