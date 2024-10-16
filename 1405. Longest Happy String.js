/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function (a, b, c) {
    let q = new MaxPriorityQueue({
        compare: (x, y) => x.count < y.count,
    });

    if (a) q.enqueue({ char: 'a', count: a });
    if (b) q.enqueue({ char: 'b', count: b });
    if (c) q.enqueue({ char: 'c', count: c });

    let str = '', three = false;

    while (q.size()) {
        let temp = q.dequeue();
        str += temp.char;
        temp.count--;

        if (temp.count && temp.char === str[str.length - 2]) {
            three = { char: temp.char, count: temp.count };
            continue;
        } else if (three) {
            q.enqueue(three);
            three = false;
        }
        if (temp.count > 0) q.enqueue(temp);
    }
    return str;
};