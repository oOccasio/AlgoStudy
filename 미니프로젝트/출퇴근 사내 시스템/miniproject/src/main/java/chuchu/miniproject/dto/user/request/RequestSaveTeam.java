package chuchu.miniproject.dto.user.request;

import lombok.Getter;
import lombok.RequiredArgsConstructor;

@Getter
@RequiredArgsConstructor
public class RequestSaveTeam {

    private final String name;
    private final String manager;
    private final int memberCount;

}
