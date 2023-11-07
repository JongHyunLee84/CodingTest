import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var priorities = priorities
    var array = [Int](0..<priorities.count)
    var index = 1
    while true {
        if priorities[array[0]] == priorities.max()! {
            if array[0] == location { return index }
            else { priorities[array[0]] = 0; array.removeFirst(); index+=1; }
        } else {
            let temp = array.removeFirst()
            array.append(temp)
        }
    }
    return 0 
}