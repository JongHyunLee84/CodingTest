import Foundation

func solution(_ my_string:String) -> Int {
    var numArray : [String] = []
    var oper : [Character] = []
    var chr : String = ""

    var index = 0
    for i in my_string {
        if i.isNumber {
            chr += String(i)
        } else if i == "+" {
            oper.append(i)
        } else if i == "-" {
            oper.append(i)
        }
        else {
            numArray.append(chr)
            chr = ""
        }
    }
    numArray.append(chr)
    var array = numArray.compactMap{ Int($0) }
    print(numArray)
    var num = array[0]
    
    if numArray.count == 2 {
        if oper[index] == "+" {
            num += array[1]
        } else {
            num -= array[1]
        }
    } else {
        for i in 1..<array.count {
            if oper[index] == "+" {
                num += array[i]
                index += 1
            } else {
                num -= array[i]
                index += 1
            }
        }
    }
    
    return num
}