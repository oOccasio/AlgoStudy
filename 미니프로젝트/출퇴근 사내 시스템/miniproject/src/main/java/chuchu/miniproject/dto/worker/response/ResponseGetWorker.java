package chuchu.miniproject.dto.worker.response;

import chuchu.miniproject.domain.Role;
import chuchu.miniproject.domain.Worker;
import lombok.Getter;
import lombok.RequiredArgsConstructor;

import java.time.LocalDate;

@RequiredArgsConstructor
@Getter
public class ResponseGetWorker {

    private final String name;
    private final String teamName;
    private final Role role;
    private final LocalDate birthday;
    private final LocalDate workStartDate;

    public ResponseGetWorker(Worker worker) {
        this.name = worker.getName();
        this.teamName = worker.getTeamName();
        this.role = worker.getRole();
        this.birthday = worker.getBirthday();
        this.workStartDate = worker.getWorkStartDate();
    }
}
