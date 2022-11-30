import Foundation
func solution(_ id_pw:[String], _ db:[[String]]) -> String {
    var result = "fail"
    for i in db {

        if i[0] == id_pw[0] && i[1] != id_pw[1] {
            result = "wrong pw"
        } else if i[0] == id_pw[0] && i[1] == id_pw[1] {
            result = "login"
        }
    }
    return result
}
