import Foundation

func solution(_ num:Int, _ total:Int) -> [Int] {
     var n = total / num 
     var array : [Int] = []
     var index = (num - 1) / 2
    var secondIndex = (num - 2) / 2
    if total % num == 0 {
       array.append(n)
        for _ in 0..<index {
            array.insert(array[0] - 1, at: 0)
            array.append(array[array.count-1] + 1)
        }
        
    } else {
        array.append(n)
        array.append(n+1)
        for _ in 0..<secondIndex {
         array.insert(array[0] - 1, at: 0)
            array.append(array[array.count-1] + 1)
        }
    }
    return array.sorted()
}