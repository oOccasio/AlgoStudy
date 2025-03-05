package chuchu.miniproject.service.worker;

import chuchu.miniproject.domain.Role;
import chuchu.miniproject.domain.Team;
import chuchu.miniproject.domain.worker.WorkList;
import chuchu.miniproject.domain.worker.Worker;
import chuchu.miniproject.dto.worker.request.RequestGoWorker;
import chuchu.miniproject.dto.worker.request.RequestLeaveWorker;
import chuchu.miniproject.dto.worker.request.RequestSaveWorker;
import chuchu.miniproject.dto.worker.response.ResponseGetWorker;
import chuchu.miniproject.repository.team.TeamRepository;
import chuchu.miniproject.repository.worker.WorkListRepository;
import chuchu.miniproject.repository.worker.WorkerRepository;
import jakarta.persistence.EntityNotFoundException;
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
    private final TeamRepository teamRepository;
    private final WorkListRepository workListRepository;


    @Transactional
    public void saveWorker(RequestSaveWorker requestSaveWorker){
        String name = requestSaveWorker.getName();
        String teamName = requestSaveWorker.getTeamName();
        Role role = requestSaveWorker.getRole();
        LocalDate birthday = requestSaveWorker.getBirthday();
        LocalDate workStartDate = requestSaveWorker.getWorkStartDate();
        Team team = teamRepository.findByName(teamName).
                orElseThrow(() -> new EntityNotFoundException(String.format("존재하지 않는 팀이름 입니다: %s", teamName)));

        if(name == null || name.trim().isEmpty()){
            throw new IllegalArgumentException("이름은 필수항목입니다.");
        }

        if(teamName == null || teamName.trim().isEmpty()){
            throw new IllegalArgumentException("팀이름은 필수항목입니다.");
        }

        if(role != Role.MANAGER && role != Role.WORKER){
            throw new IllegalArgumentException("유효하지 않은 역할입니다: " + role);
        }
        if(role == Role.MANAGER && team.getManager() != null){
            throw new IllegalArgumentException("이미 매니저가 있는 팀입니다.");
        }
        if(role == Role.MANAGER) {
            team.updateManager(name);
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
                .team(team)
                .build();

        team.addWorker(worker);
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


    @Transactional
    public void goWorker(RequestGoWorker requestGoWorker){
        Long currentId = requestGoWorker.workerId();
        Worker currentWorker = workerRepository.findById(currentId)
                .orElseThrow(() -> new EntityNotFoundException("존재하지 않는 Id 입니다."));

        LocalDate workDate = requestGoWorker.workDate();

        Integer workingMinute = requestGoWorker.workingMinutes();

        if(workDate == null){
            throw new IllegalArgumentException("유효한 날짜를 입력해주세요.");
        }

        if(workDate.isAfter(LocalDate.now())) {
            throw new IllegalArgumentException("미래 날짜는 입력할 수 없습니다.");
        }

        if(workDate.isBefore(currentWorker.getWorkStartDate())){
            throw new IllegalArgumentException("입사일 이전의 날짜는 입력할 수 없습니다.");
        }

        if(workingMinute == null || workingMinute <= 0) {
            throw new IllegalArgumentException("유효한 시간을 입력해주세요");
        }

        WorkList workList = WorkList.builder()
                .work(true)
                .worker(currentWorker)
                .workDate(workDate)
                .workingMinutes(workingMinute).build();

        currentWorker.goWork(workList);

    }


    @Transactional
    public void leaveWorker(RequestLeaveWorker requestLeaveWorker){

        WorkList currentWorkList = workListRepository
                .findByWorkerIdAndWorkDate(requestLeaveWorker.workerId(), requestLeaveWorker.workDate())
                .orElseThrow(() -> new EntityNotFoundException("출근 리스트에 없는 직원입니다."));

        if(!currentWorkList.isWork())
            throw new IllegalArgumentException("출근하지 않은 직원입니다.");

        currentWorkList.isNotWorking();

    }



}
