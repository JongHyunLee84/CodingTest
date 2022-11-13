import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    var array: [Int] = []
    var evenArray: [Int] = []
    var oddArray: [Int] = []
    // 짝수의 갯수를 셈 
    for i in num_list {
        if i % 2 == 0 {
            evenArray.append(i)
            
        }
    }
    array.append(evenArray.count)
        for i in num_list {
        if i % 2 != 0 {
            oddArray.append(i)  
            
        }
        }
    array.append(oddArray.count)
            return array
}