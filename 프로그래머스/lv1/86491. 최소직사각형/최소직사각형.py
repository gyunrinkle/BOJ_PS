def solution(sizes):
    answer = 0
    widths = []
    heights = []
    for width, height in sizes:
        if width > height:
            width, height = height, width

        widths.append(width)
        heights.append(height)

    max_width, max_height = max(widths), max(heights)

    answer = max_width * max_height
    return answer