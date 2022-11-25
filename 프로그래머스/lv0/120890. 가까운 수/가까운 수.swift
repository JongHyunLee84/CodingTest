import Foundation


func solution(_ array:[Int], _ n:Int) -> Int {
    var arrays : [Int] = []
    var result = 100
   for i in array.sorted() {
       arrays.append(n - i) 
   }
    for i in arrays {
        if abs(i) < result {
            result = i
        }
    }
    if result > 0 {
        return array[array.firstIndex(of: n - result )!]
    } else {
        return array[array.firstIndex(of: n + abs(result))!]
    }
    
}