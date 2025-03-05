package chuchu.miniproject.controller.worker;

import chuchu.miniproject.dto.worker.request.RequestGoWorker;
import chuchu.miniproject.dto.worker.request.RequestLeaveWorker;
import chuchu.miniproject.dto.worker.request.RequestSaveWorker;
import chuchu.miniproject.dto.worker.response.ResponseGetWorker;
import chuchu.miniproject.service.worker.WorkerService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api")
public class WorkerController {

    private final WorkerService workerService;


    @PostMapping("/worker")
    public void saveWorker(@RequestBody RequestSaveWorker requestSaveWorker) {
        workerService.saveWorker(requestSaveWorker);
    }

    @GetMapping("/worker")
    public List<ResponseGetWorker> getWorkers() {
        return workerService.getWorkers();
    }


    @PostMapping("/worker/go")
    public void goWorker (@RequestBody RequestGoWorker requestGoWorker) {
        workerService.goWorker(requestGoWorker);
    }

    @PostMapping("/worker/leave")
    public void leaveWorker(@RequestBody RequestLeaveWorker requestLeaveWorker) {
        workerService.leaveWorker(requestLeaveWorker);
    }


}
