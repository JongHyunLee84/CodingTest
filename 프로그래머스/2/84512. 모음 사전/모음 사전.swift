import Foundation
var original = ""
var ret = 1
func solution(_ word:String) -> Int {
    original = word
    go("A")
    return ret
}

func go(_ word: String) {
    if word == original { return }
    if word == "UUUUU" { return }
    if word != "UUUUU" && word.count != 5 {
        ret += 1
        go(word + "A")
    }
    if word.count == 5 {
        ret += 1
        go(plusWord(word))
    }
}

func plusWord(_ word: String) -> String {
    var temp = ""
    var isPlused = false
    for i in word.reversed() {
        if !isPlused {
            if i == "A" {
                temp += "E"
                isPlused = true
                continue
            } else if i == "E" {
                temp += "I"
                isPlused = true
                continue
            }else if i == "I" {
                temp += "O"
                isPlused = true
                continue
            } else if i == "O" {
                temp += "U"
                isPlused = true
                continue
            } else {
                continue
            }
        }
        // print(i)
        temp += String(i)
    }
    return String(temp.reversed())
}

