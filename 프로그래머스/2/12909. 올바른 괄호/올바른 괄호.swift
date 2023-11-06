// import Foundation

// func solution(_ s:String) -> Bool
// {
//     var array: [Character] = []
//     for char in s {
//         if array.count > 0 {
//             if array.first! == "(" && char == ")" {
//                 array.removeFirst()
//             } else {
//                 array.insert(char, at: 0)
//             }
//         } else {
//                 array.insert(char, at: 0)
//         }
//         if array.count > 0, array.last! == ")" { return false }
//     }
//     if array.count > 0 {
//         return false
//     } else {
//         return true
//     }
// }


import Foundation

func solution(_ s:String) -> Bool
{
    var brackets:[String] = []

    for c in s {
        if c == "(" {
            brackets.append(String(c))
        }

        else {
            if brackets.count == 0 {
                return false
            }

            else {
                brackets.removeLast()
            }
        }
    }

    if brackets.count != 0 {
        return false
    }

    return true
}
