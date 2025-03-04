package chuchu.miniproject.dto.worker.response;

import chuchu.miniproject.domain.Role;
import chuchu.miniproject.domain.Worker;
import lombok.Builder;
import lombok.Getter;
import lombok.RequiredArgsConstructor;

import java.time.LocalDate;

@Getter
@Builder
public class ResponseGetWorker {

    private final String name;
    private final String teamName;
    private final Role role;
    private final LocalDate birthday;
    private final LocalDate workStartDate;


}
