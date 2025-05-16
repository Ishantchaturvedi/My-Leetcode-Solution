class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        prev_index = [0] * n
        hash_map = {}

        max_len = 0
        start_index = 0

        for i in range(n - 1, -1, -1):
            word = words[i]
            group = groups[i]

            # Create a base hash using 6 bits per character (ASCII & 31 ensures only lower 5 bits)
            base_hash = sum((ord(c) & 31) << (j * 6) for j, c in enumerate(word))
            best_len = 0

            # Try mutating each character into a wildcard (bitmask 31)
            for j in range(len(word)):
                mutated_hash = base_hash | (31 << (j * 6))
                max1, idx1, max2, idx2 = hash_map.get(mutated_hash, (0, 0, 0, 0))

                if groups[idx1] != group:
                    if max1 > best_len:
                        best_len = max1
                        prev_index[i] = idx1
                elif max2 > best_len:
                    best_len = max2
                    prev_index[i] = idx2

            best_len += 1
            if best_len > max_len:
                max_len = best_len
                start_index = i

            # Update hash_map with new entry or improve existing one
            for j in range(len(word)):
                mutated_hash = base_hash | (31 << (j * 6))
                max1, idx1, max2, idx2 = hash_map.get(mutated_hash, (0, 0, 0, 0))

                if best_len > max1:
                    if groups[idx1] != group:
                        max2, idx2 = max1, idx1
                    max1, idx1 = best_len, i
                elif best_len > max2 and groups[idx1] != group:
                    max2, idx2 = best_len, i

                hash_map[mutated_hash] = (max1, idx1, max2, idx2)

        # Reconstruct result using prev_index
        result = []
        index = start_index
        for _ in range(max_len):
            result.append(words[index])
            index = prev_index[index]

        return result