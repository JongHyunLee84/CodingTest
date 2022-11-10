import Foundation

func solution(_ array:[Int], _ height:Int) -> Int {
    var i = 0
    var sortedArray = array.sorted()
    while height >= sortedArray[i] {
        
        i += 1
        if i == sortedArray.count {
            break
        }
        
    }
    // array[i] 인덱스부터 array 마지막 인덱스까지의 수
    var result = array.count - i
    return result
}