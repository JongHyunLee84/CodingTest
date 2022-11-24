import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [[Int]] {
    // num_list.count -> n * count/4 배열로 만든다.
    var twoDArray : [[Int]] = []
    var array : [Int] = []
    for i in num_list {
        array.append(i)
        if array.count == n {
            twoDArray.append(array)
            array = []
        }
    }
    return twoDArray
}