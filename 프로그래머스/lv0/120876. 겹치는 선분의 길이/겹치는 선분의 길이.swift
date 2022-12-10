import Foundation

func solution(_ lines:[[Int]]) -> Int {
    var array : [Int] = []
    var all : [[Int]] = []
    var error = 0
    for i in lines {
        var count = i[0]
        var a : [Int] = []
        while count <= i[1] {
            
            a.append(count)
            count += 1
            
        }
        all.append(a)
    }
 
     var line1 : [Int] = all[0]
     var line2 : [Int] = all[1]
     var line3 : [Int] = all[2]
    
    for i in line1 {
        if line2.contains(i) {
            array.append(i)
        }
        if line3.contains(i) {
            array.append(i)
        }
    }
    if array.count == 1 {
        error += 1
    }
    for i in line3 {
        if line2.contains(i) {
            array.append(i)
        }
    }
    if error == 1 && array.count >= 2 {
        return 0
    }
    var result = Set(array).sorted()
    var length = 0
    for i in 0..<result.count {
        if i == result.count - 1 {
            break
        }
        if result[i] + 1 == result[i + 1] {
            length += 1
        }
    }
    
    return length
}