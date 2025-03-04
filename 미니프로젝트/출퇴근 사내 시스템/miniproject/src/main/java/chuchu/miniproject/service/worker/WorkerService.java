package chuchu.miniproject.service.worker;

import chuchu.miniproject.domain.Role;
import chuchu.miniproject.domain.Worker;
import chuchu.miniproject.dto.worker.request.RequestSaveWorker;
import chuchu.miniproject.dto.worker.response.ResponseGetWorker;
import chuchu.miniproject.repository.worker.WorkerRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDate;
import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class WorkerService {

    private final WorkerRepository workerRepository;


    @Transactional
    public void saveWorker(RequestSaveWorker requestSaveWorker){
        String name = requestSaveWorker.getName();
        String teamName = requestSaveWorker.getTeamName();
        Role role = requestSaveWorker.getRole();
        LocalDate birthday = requestSaveWorker.getBirthday();
        LocalDate workStartDate = requestSaveWorker.getWorkStartDate();


        if(name == null || name.trim().isEmpty()){
            throw new IllegalArgumentException(String.format("유효하지 않은 이름입니다: %s", name));
        }

        if(teamName == null || teamName.trim().isEmpty()){
            throw new IllegalArgumentException(String.format("유효하지 않은 팀이름입니다: %s", teamName));
        }

        if(role != Role.MANAGER && role != Role.WORKER){
            throw new IllegalArgumentException("유효하지 않은 역할입니다: " + role);
        }

        if(birthday.isAfter(LocalDate.now()) || birthday.isBefore(LocalDate.of(1900, 1, 1))){
            throw new IllegalArgumentException("유효한 생년월일을 입력해주세요");
        }


        if(workStartDate.isAfter(LocalDate.now()) || workStartDate.isBefore(LocalDate.of(1900, 1, 1))) {
            throw new IllegalArgumentException("유효한 입사일을 입력해주세요");
        }

        Worker worker = Worker.builder()
                .name(requestSaveWorker.getName())
                .teamName(requestSaveWorker.getTeamName())
                .role(requestSaveWorker.getRole())
                .birthday(requestSaveWorker.getBirthday())
                .workStartDate(requestSaveWorker.getWorkStartDate())
                .build();

        workerRepository.save(worker);
    }

    @Transactional(readOnly = true)
    public List<ResponseGetWorker> getWorkers(){
        return workerRepository.findAll().stream()
                .map(worker -> ResponseGetWorker.builder()
                                .name(worker.getName())
                                .teamName(worker.getTeamName())
                                .role(worker.getRole())
                                .birthday(worker.getBirthday())
                                .workStartDate(worker.getWorkStartDate())
                                .build()).collect(Collectors.toList());
    }
}
