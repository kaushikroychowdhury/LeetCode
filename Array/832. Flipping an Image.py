class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        # print(image[0][::-1])
        inverted_image = []
        l = len(image)
        for i in range(0,l):
            inverted_image.append(image[i][::-1])
            
        for i in inverted_image:
            for j in range(0, len(i)):
                if i[j] == 0:
                    i[j] = 1
                else:
                    i[j] = 0
                    
        return inverted_image