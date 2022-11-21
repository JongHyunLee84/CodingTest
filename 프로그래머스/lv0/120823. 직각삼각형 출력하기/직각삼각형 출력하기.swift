import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }

for i in 1...n[0] {
    switch i {
        case 1 :
        print("*", terminator: "\n")
        case 2 :
         print("**", terminator: "\n")
        case 3 :
         print("***", terminator: "\n")
        case 4 :
         print("****", terminator: "\n")
        case 5 :
         print("*****", terminator: "\n")
        case 6 :
         print("******", terminator: "\n")
        case 7 :
         print("*******", terminator: "\n")
        case 8 :
         print("********", terminator: "\n")
        case 9 :
         print("*********", terminator: "\n")
        case 10 :
         print("**********", terminator: "\n")
        default:
        break
    }
    
}