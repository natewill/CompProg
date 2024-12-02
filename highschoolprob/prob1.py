def can_form_teams(skill_levels, target_sum, teams, used, index):
    if teams == 0:
        return True
    if target_sum == 0:
        # Start forming the next team
        return can_form_teams(skill_levels, total_team_sum, teams - 1, used, 0)
    for i in range(index, len(skill_levels)):
        if not used[i] and skill_levels[i] <= target_sum:
            used[i] = True
            if can_form_teams(skill_levels, target_sum - skill_levels[i], teams, used, i + 1):
                return True
            used[i] = False
            # Optimization: if this student cannot be placed, skip students with the same skill level
            while i + 1 < len(skill_levels) and skill_levels[i] == skill_levels[i + 1]:
                i += 1
    return False

def main():
    N = int(input())
    if N % 3 != 0:
        print("NO")
        return
    skill_levels = list(map(int, input().split()))
    total_sum = sum(skill_levels)
    num_teams = N // 3
    if total_sum % num_teams != 0:
        print("NO")
        return
    global total_team_sum
    total_team_sum = total_sum // num_teams
    skill_levels.sort(reverse=True)
    used = [False] * N
    if can_form_teams(skill_levels, total_team_sum, num_teams, used, 0):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()