package chuchu.miniproject.dto.user.response;

import chuchu.miniproject.domain.Team;
import lombok.Getter;
import lombok.NoArgsConstructor;


@NoArgsConstructor
@Getter
public class ResponseGetTeam {
    private String name;
    private String manager;
    private int memberCount;

    public ResponseGetTeam(Team team) {
        this.name = team.getName();
        this.manager = team.getManager();
        this.memberCount = team.getMemberCount();
    }
}
