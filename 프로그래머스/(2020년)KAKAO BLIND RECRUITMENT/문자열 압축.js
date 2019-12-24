param = ["aabbaccc", "ababcdcdababcdcd", "abcabcdede", "abcabcabcabcdededededede","xababcdcdababcdcd"];

function solution(s) {
    let answer = s.length;
    for (let i = 1; i < s.length; i++) {
        let localSize = 0;
        let shortNum = 0;
        let pre;
        for (let j = 0; j < s.length; j+=i) {
            const cur = s.substr(j, i);
            if (pre === cur) {
                shortNum += 1;
            } else {
                pre = cur;
                localSize += shortNum > 1 ? shortNum.toString().length + cur.length : cur.length;
                shortNum = 1; 
            }
        }
        if (shortNum > 1) localSize += shortNum.toString().length;
        answer = localSize < answer ? localSize : answer;
    }
    return answer;
}

param.forEach(s => console.log(solution(s)));
