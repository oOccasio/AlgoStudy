package chuchu.miniproject.service.worker;

import chuchu.miniproject.domain.Worker;
import chuchu.miniproject.dto.worker.request.RequestSaveWorker;
import chuchu.miniproject.dto.worker.response.ResponseGetWorker;
import chuchu.miniproject.repository.worker.WorkerRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class WorkerService {

    private final WorkerRepository workerRepository;


    @Transactional
    public void saveWorker(RequestSaveWorker requestSaveWorker){
        Worker worker = workerRepository.save(new Worker(requestSaveWorker.getName(),
                requestSaveWorker.getTeamName(),
                requestSaveWorker.getRole(),
                requestSaveWorker.getBirthday(),
                requestSaveWorker.getWorkStartDate()));
    }

    @Transactional(readOnly = true)
    public List<ResponseGetWorker> getWorkers(){
        return workerRepository.findAll().stream()
                .map(ResponseGetWorker :: new)
                .collect(Collectors.toList());
    }
}
