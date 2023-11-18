import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var ret: Int = .max
    var visited = Array(repeating: false, count: words.count)
    
    func onlyOne(_ first: String, _ second: String) -> Bool {
        var diff = 0
        for i in 0..<first.count {
            if Array(first)[i] != Array(second)[i] {
                if diff > 0 { return false }
                else { diff += 1 }
            }
        }
        return true
    }
    
    func dfs(_ word: String, _ cnt: Int) {
        if cnt > words.count { return }
        if word == target {
            ret = min(ret, cnt)
            return 
        }
        
        for i in 0..<words.count {
            if !visited[i], onlyOne(word, words[i]) {
                visited[i] = true
                dfs(words[i], cnt+1)
                visited[i] = false
            }
        }
    }
    dfs(begin, 0)
    if ret == .max { return 0 }
    else { return ret }
}