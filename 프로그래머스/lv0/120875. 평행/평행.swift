import Foundation

func solution(_ dots:[[Int]]) -> Int {
    var array1 : [Double] = []
    var array2 : [Double] = []
    var dots1 = dots
    var result = 0
    for i in 1..<dots.count {
        var x = dots[0][0] - dots[i][0]
        var y = dots[0][1] - dots[i][1]
        var g = Double(y) / Double(x)
        array1.append(g)
    }
    
    for i in 2..<dots.count {
        var x = dots[1][0] - dots[i][0]
        var y = dots[1][1] - dots[i][1]
        var g = Double(y) / Double(x)
        array2.append(g)
    }
    
    for i in 3..<dots.count {
        var x = dots[2][0] - dots[i][0]
        var y = dots[2][1] - dots[i][1]
        var g = Double(y) / Double(x)
        array2.append(g)
    }
    
    for i in array1 {
        if array2.contains(i) {
            result = 1
        }
    }
    return result
}